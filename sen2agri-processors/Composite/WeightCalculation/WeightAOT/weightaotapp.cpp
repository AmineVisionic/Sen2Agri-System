
/*=========================================================================

 Program:   ORFEO Toolbox
 Language:  C++
 Date:      $Date$
 Version:   $Revision$


 Copyright (c) Centre National d'Etudes Spatiales. All rights reserved.
 See OTBCopyright.txt for details.


 This software is distributed WITHOUT ANY WARRANTY; without even
 the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 PURPOSE.  See the above copyright notices for more information.

 =========================================================================*/
#include "otbWrapperApplication.h"
#include "otbWrapperApplicationFactory.h"

#include "weightonaot.h"

namespace otb
{

namespace Wrapper
{

class WeightAOT : public Application
{

public:
  /** Standard class typedefs. */
  typedef WeightAOT                      Self;
  typedef Application                   Superclass;
  typedef itk::SmartPointer<Self>       Pointer;
  typedef itk::SmartPointer<const Self> ConstPointer;

  /** Standard macro */
  itkNewMacro(Self);

  itkTypeMacro(WeightAOT, otb::Application);

private:
  void DoInit()
  {
    SetName("WeightAOT");
    SetDescription("Perform a mathematical operation on monoband images");

    SetDocName("Weight AOT");
    SetDocLongDescription("This is inspired from the OTB application OTB-5.0.0/Modules/Applications/AppMathParser/app/otbBandMath.cxx");

    SetDocLimitations("None");
    SetDocAuthors("CIU");
    SetDocSeeAlso(" ");
    AddDocTag("Util");

    AddParameter(ParameterType_String,  "in",   "Input image");
    SetParameterDescription("in", "Image containing AOT.");

    AddParameter(ParameterType_Int, "band", "Expression");
    SetParameterDescription("band", "The AOT band from the input image.");

    AddParameter(ParameterType_OutputImage, "out", "Output Image");
    SetParameterDescription("out","Output image.");

    AddParameter(ParameterType_Float, "qaot", "AOTQuantificationValue");
    SetParameterDescription("qaot", "AOT quantification value");

    AddParameter(ParameterType_Float, "waotmin", "WeightAOTMin");
    SetParameterDescription("waotmin", "min weight depending on AOT");

    AddParameter(ParameterType_Float, "waotmax", "WeightAOTMax");
    SetParameterDescription("waotmax", "max weight depending on AOT");

    AddParameter(ParameterType_Int, "aotmax", "AOTMax");
    SetParameterDescription("aotmax",
        "maximum value of the linear range for weights w.r.t AOT to which the quantification value is applied");

    AddRAMParameter();

    // Doc example parameter settings
    SetDocExampleParameterValue("in", "verySmallFSATSW_r.tif");
    SetDocExampleParameterValue("band", "2");
    SetDocExampleParameterValue("qaot", "0.005");
    SetDocExampleParameterValue("waotmin", "0.33");
    SetDocExampleParameterValue("waotmax", "1");
    SetDocExampleParameterValue("aotmax", "50");
    SetDocExampleParameterValue("out", "apAOTWeightOutput.tif");
  }

  void DoUpdateParameters()
  {
  }

  void DoExecute()
  {
    // Get the input image list
    std::string inImgStr = GetParameterString("in");
    if (inImgStr.empty())
    {
        itkExceptionMacro("No input Image set...; please set the input image");
    }

    int nBand = GetParameterInt("band");
    float fAotQuantificationVal = GetParameterFloat("qaot");
    int nAotMax = GetParameterInt("aotmax");
    float fWaotMin = GetParameterFloat("waotmin");
    float fWaotMax = GetParameterFloat("waotmax");

    m_weightOnAot.SetInputFileName(inImgStr);
    m_weightOnAot.SetBand(nBand);
    m_weightOnAot.SetAotQuantificationValue(fAotQuantificationVal);
    m_weightOnAot.SetAotMaxValue(nAotMax);
    m_weightOnAot.SetMinAotWeight(fWaotMin);
    m_weightOnAot.SetMaxAotWeight(fWaotMax);
    m_weightOnAot.Update();

    // Set the output image
    SetParameterOutputImage("out", m_weightOnAot.GetOutputImageSource()->GetOutput());
  }

  WeightOnAOT m_weightOnAot;
};

} // namespace Wrapper
} // namespace otb

OTB_APPLICATION_EXPORT(otb::Wrapper::WeightAOT)
