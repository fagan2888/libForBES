#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/examples/matop_example.o \
	${OBJECTDIR}/examples/matrix_example.o \
	${OBJECTDIR}/examples/qp_box.o \
	${OBJECTDIR}/examples/shallow_example.o \
	${OBJECTDIR}/source/CGSolver.o \
	${OBJECTDIR}/source/CholeskyFactorization.o \
	${OBJECTDIR}/source/ConjugateFunction.o \
	${OBJECTDIR}/source/DistanceToBall2.o \
	${OBJECTDIR}/source/DistanceToBox.o \
	${OBJECTDIR}/source/ElasticNet.o \
	${OBJECTDIR}/source/FBCache.o \
	${OBJECTDIR}/source/FBProblem.o \
	${OBJECTDIR}/source/FBSplitting.o \
	${OBJECTDIR}/source/FBSplittingFast.o \
	${OBJECTDIR}/source/FBStopping.o \
	${OBJECTDIR}/source/FBStoppingRelative.o \
	${OBJECTDIR}/source/FactoredSolver.o \
	${OBJECTDIR}/source/ForBESUtils.o \
	${OBJECTDIR}/source/Function.o \
	${OBJECTDIR}/source/FunctionOntologicalClass.o \
	${OBJECTDIR}/source/FunctionOntologyRegistry.o \
	${OBJECTDIR}/source/HingeLoss.o \
	${OBJECTDIR}/source/HuberLoss.o \
	${OBJECTDIR}/source/IndBall2.o \
	${OBJECTDIR}/source/IndBox.o \
	${OBJECTDIR}/source/IndPos.o \
	${OBJECTDIR}/source/IndProbSimplex.o \
	${OBJECTDIR}/source/IndSOC.o \
	${OBJECTDIR}/source/LBFGSBuffer.o \
	${OBJECTDIR}/source/LDLFactorization.o \
	${OBJECTDIR}/source/LQCost.o \
	${OBJECTDIR}/source/LinOpSolver.o \
	${OBJECTDIR}/source/LinSysSolver.o \
	${OBJECTDIR}/source/LinearOperator.o \
	${OBJECTDIR}/source/LogLogisticLoss.o \
	${OBJECTDIR}/source/Matrix.o \
	${OBJECTDIR}/source/MatrixFactory.o \
	${OBJECTDIR}/source/MatrixOperator.o \
	${OBJECTDIR}/source/MatrixSolver.o \
	${OBJECTDIR}/source/MatrixWriter.o \
	${OBJECTDIR}/source/Norm.o \
	${OBJECTDIR}/source/Norm1.o \
	${OBJECTDIR}/source/Norm2.o \
	${OBJECTDIR}/source/OpAdjoint.o \
	${OBJECTDIR}/source/OpComposition.o \
	${OBJECTDIR}/source/OpDCT2.o \
	${OBJECTDIR}/source/OpDCT3.o \
	${OBJECTDIR}/source/OpGradient.o \
	${OBJECTDIR}/source/OpGradient2D.o \
	${OBJECTDIR}/source/OpLTI.o \
	${OBJECTDIR}/source/OpLinearCombination.o \
	${OBJECTDIR}/source/OpReverseVector.o \
	${OBJECTDIR}/source/OpSum.o \
	${OBJECTDIR}/source/Properties.o \
	${OBJECTDIR}/source/QuadOverAffine.o \
	${OBJECTDIR}/source/Quadratic.o \
	${OBJECTDIR}/source/QuadraticLoss.o \
	${OBJECTDIR}/source/QuadraticLossOverAffine.o \
	${OBJECTDIR}/source/QuadraticOperator.o \
	${OBJECTDIR}/source/S_LDLFactorization.o \
	${OBJECTDIR}/source/SeparableSum.o \
	${OBJECTDIR}/source/SeparableSumOrdered.o \
	${OBJECTDIR}/source/SumOfNorm2.o \
	${OBJECTDIR}/source/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f22 \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f11 \
	${TESTDIR}/TestFiles/f12 \
	${TESTDIR}/TestFiles/f13 \
	${TESTDIR}/TestFiles/f14 \
	${TESTDIR}/TestFiles/f15 \
	${TESTDIR}/TestFiles/f16 \
	${TESTDIR}/TestFiles/f17 \
	${TESTDIR}/TestFiles/f18 \
	${TESTDIR}/TestFiles/f19 \
	${TESTDIR}/TestFiles/f20 \
	${TESTDIR}/TestFiles/f21 \
	${TESTDIR}/TestFiles/f23 \
	${TESTDIR}/TestFiles/f24 \
	${TESTDIR}/TestFiles/f25 \
	${TESTDIR}/TestFiles/f27 \
	${TESTDIR}/TestFiles/f28 \
	${TESTDIR}/TestFiles/f29 \
	${TESTDIR}/TestFiles/f30 \
	${TESTDIR}/TestFiles/f31 \
	${TESTDIR}/TestFiles/f32 \
	${TESTDIR}/TestFiles/f33 \
	${TESTDIR}/TestFiles/f34 \
	${TESTDIR}/TestFiles/f35 \
	${TESTDIR}/TestFiles/f36 \
	${TESTDIR}/TestFiles/f37 \
	${TESTDIR}/TestFiles/f38 \
	${TESTDIR}/TestFiles/f39 \
	${TESTDIR}/TestFiles/f40 \
	${TESTDIR}/TestFiles/f41 \
	${TESTDIR}/TestFiles/f42 \
	${TESTDIR}/TestFiles/f43 \
	${TESTDIR}/TestFiles/f44 \
	${TESTDIR}/TestFiles/f26 \
	${TESTDIR}/TestFiles/f45

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/source/tests/TestCGSolver.o \
	${TESTDIR}/source/tests/TestCGSolverRunner.o \
	${TESTDIR}/source/tests/TestCholesky.o \
	${TESTDIR}/source/tests/TestCholeskyRunner.o \
	${TESTDIR}/source/tests/TestConjugateFunction.o \
	${TESTDIR}/source/tests/TestConjugateFunctionRunner.o \
	${TESTDIR}/source/tests/TestDistanceToBall2.o \
	${TESTDIR}/source/tests/TestDistanceToBall2Runner.o \
	${TESTDIR}/source/tests/TestDistanceToBox.o \
	${TESTDIR}/source/tests/TestDistanceToBoxRunner.o \
	${TESTDIR}/source/tests/TestElasticNet.o \
	${TESTDIR}/source/tests/TestElasticNetRunner.o \
	${TESTDIR}/source/tests/TestFBCache.o \
	${TESTDIR}/source/tests/TestFBCacheRunner.o \
	${TESTDIR}/source/tests/TestFBProblem.o \
	${TESTDIR}/source/tests/TestFBProblemRunner.o \
	${TESTDIR}/source/tests/TestFBSplitting.o \
	${TESTDIR}/source/tests/TestFBSplittingFast.o \
	${TESTDIR}/source/tests/TestFBSplittingFastRunner.o \
	${TESTDIR}/source/tests/TestFBSplittingRunner.o \
	${TESTDIR}/source/tests/TestFunctionOntologicalClass.o \
	${TESTDIR}/source/tests/TestFunctionOntologicalClassRunner.o \
	${TESTDIR}/source/tests/TestFunctionOntologyRegistry.o \
	${TESTDIR}/source/tests/TestFunctionOntologyRegistryRunner.o \
	${TESTDIR}/source/tests/TestHingeLoss.o \
	${TESTDIR}/source/tests/TestHingeLossRunner.o \
	${TESTDIR}/source/tests/TestHuber.o \
	${TESTDIR}/source/tests/TestHuberRunner.o \
	${TESTDIR}/source/tests/TestIndBall2.o \
	${TESTDIR}/source/tests/TestIndBall2Runner.o \
	${TESTDIR}/source/tests/TestIndBox.o \
	${TESTDIR}/source/tests/TestIndBoxRunner.o \
	${TESTDIR}/source/tests/TestIndPos.o \
	${TESTDIR}/source/tests/TestIndPosRunner.o \
	${TESTDIR}/source/tests/TestIndProbSimplex.o \
	${TESTDIR}/source/tests/TestIndProbSimplexRunner.o \
	${TESTDIR}/source/tests/TestIndSOC.o \
	${TESTDIR}/source/tests/TestIndSOCRunner.o \
	${TESTDIR}/source/tests/TestLBFGSBuffer.o \
	${TESTDIR}/source/tests/TestLBFGSBufferRunner.o \
	${TESTDIR}/source/tests/TestLDL.o \
	${TESTDIR}/source/tests/TestLDLRunner.o \
	${TESTDIR}/source/tests/TestLasso.o \
	${TESTDIR}/source/tests/TestLassoRunner.o \
	${TESTDIR}/source/tests/TestLogLogisticLoss.o \
	${TESTDIR}/source/tests/TestLogLogisticLossRunner.o \
	${TESTDIR}/source/tests/TestMatrix.o \
	${TESTDIR}/source/tests/TestMatrixExtras.o \
	${TESTDIR}/source/tests/TestMatrixExtrasRunner.o \
	${TESTDIR}/source/tests/TestMatrixFactory.o \
	${TESTDIR}/source/tests/TestMatrixFactoryRunner.o \
	${TESTDIR}/source/tests/TestMatrixOperator.o \
	${TESTDIR}/source/tests/TestMatrixOperatorRunner.o \
	${TESTDIR}/source/tests/TestMatrixRunner.o \
	${TESTDIR}/source/tests/TestNorm1.o \
	${TESTDIR}/source/tests/TestNorm1Runner.o \
	${TESTDIR}/source/tests/TestNorm2.o \
	${TESTDIR}/source/tests/TestNorm2Runner.o \
	${TESTDIR}/source/tests/TestOntRegistry.o \
	${TESTDIR}/source/tests/TestOntRegistryRunner.o \
	${TESTDIR}/source/tests/TestOpAdjoint.o \
	${TESTDIR}/source/tests/TestOpAdjointRunner.o \
	${TESTDIR}/source/tests/TestOpComposition.o \
	${TESTDIR}/source/tests/TestOpCompositionRunner.o \
	${TESTDIR}/source/tests/TestOpDCT2.o \
	${TESTDIR}/source/tests/TestOpDCT2Runner.o \
	${TESTDIR}/source/tests/TestOpDCT3.o \
	${TESTDIR}/source/tests/TestOpDCT3Runner.o \
	${TESTDIR}/source/tests/TestOpGradient.o \
	${TESTDIR}/source/tests/TestOpGradientRunner.o \
	${TESTDIR}/source/tests/TestOpReverseVector.o \
	${TESTDIR}/source/tests/TestOpReverseVectorRunner.o \
	${TESTDIR}/source/tests/TestProperties.o \
	${TESTDIR}/source/tests/TestPropertiesRunner.o \
	${TESTDIR}/source/tests/TestQuadOverAffine.o \
	${TESTDIR}/source/tests/TestQuadOverAffineRunner.o \
	${TESTDIR}/source/tests/TestQuadratic.o \
	${TESTDIR}/source/tests/TestQuadraticLoss.o \
	${TESTDIR}/source/tests/TestQuadraticLossOverAffine.o \
	${TESTDIR}/source/tests/TestQuadraticLossOverAffineRunner.o \
	${TESTDIR}/source/tests/TestQuadraticLossRunner.o \
	${TESTDIR}/source/tests/TestQuadraticOperator.o \
	${TESTDIR}/source/tests/TestQuadraticOperatorRunner.o \
	${TESTDIR}/source/tests/TestQuadraticRunner.o \
	${TESTDIR}/source/tests/TestSLDL.o \
	${TESTDIR}/source/tests/TestSLDLRunner.o \
	${TESTDIR}/source/tests/TestSeparableSum.o \
	${TESTDIR}/source/tests/TestSeparableSumRunner.o \
	${TESTDIR}/source/tests/TestSumOfNorm2.o \
	${TESTDIR}/source/tests/TestSumOfNorm2Runner.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libforbes

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libforbes: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libforbes ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/examples/matop_example.o: examples/matop_example.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/matop_example.o examples/matop_example.cpp

${OBJECTDIR}/examples/matrix_example.o: examples/matrix_example.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/matrix_example.o examples/matrix_example.cpp

${OBJECTDIR}/examples/qp_box.o: examples/qp_box.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/qp_box.o examples/qp_box.cpp

${OBJECTDIR}/examples/shallow_example.o: examples/shallow_example.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/shallow_example.o examples/shallow_example.cpp

${OBJECTDIR}/source/CGSolver.o: source/CGSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/CGSolver.o source/CGSolver.cpp

${OBJECTDIR}/source/CholeskyFactorization.o: source/CholeskyFactorization.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/CholeskyFactorization.o source/CholeskyFactorization.cpp

${OBJECTDIR}/source/ConjugateFunction.o: source/ConjugateFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ConjugateFunction.o source/ConjugateFunction.cpp

${OBJECTDIR}/source/DistanceToBall2.o: source/DistanceToBall2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/DistanceToBall2.o source/DistanceToBall2.cpp

${OBJECTDIR}/source/DistanceToBox.o: source/DistanceToBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/DistanceToBox.o source/DistanceToBox.cpp

${OBJECTDIR}/source/ElasticNet.o: source/ElasticNet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ElasticNet.o source/ElasticNet.cpp

${OBJECTDIR}/source/FBCache.o: source/FBCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBCache.o source/FBCache.cpp

${OBJECTDIR}/source/FBProblem.o: source/FBProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBProblem.o source/FBProblem.cpp

${OBJECTDIR}/source/FBSplitting.o: source/FBSplitting.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBSplitting.o source/FBSplitting.cpp

${OBJECTDIR}/source/FBSplittingFast.o: source/FBSplittingFast.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBSplittingFast.o source/FBSplittingFast.cpp

${OBJECTDIR}/source/FBStopping.o: source/FBStopping.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBStopping.o source/FBStopping.cpp

${OBJECTDIR}/source/FBStoppingRelative.o: source/FBStoppingRelative.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBStoppingRelative.o source/FBStoppingRelative.cpp

${OBJECTDIR}/source/FactoredSolver.o: source/FactoredSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FactoredSolver.o source/FactoredSolver.cpp

${OBJECTDIR}/source/ForBESUtils.o: source/ForBESUtils.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ForBESUtils.o source/ForBESUtils.cpp

${OBJECTDIR}/source/Function.o: source/Function.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Function.o source/Function.cpp

${OBJECTDIR}/source/FunctionOntologicalClass.o: source/FunctionOntologicalClass.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FunctionOntologicalClass.o source/FunctionOntologicalClass.cpp

${OBJECTDIR}/source/FunctionOntologyRegistry.o: source/FunctionOntologyRegistry.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FunctionOntologyRegistry.o source/FunctionOntologyRegistry.cpp

${OBJECTDIR}/source/HingeLoss.o: source/HingeLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/HingeLoss.o source/HingeLoss.cpp

${OBJECTDIR}/source/HuberLoss.o: source/HuberLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/HuberLoss.o source/HuberLoss.cpp

${OBJECTDIR}/source/IndBall2.o: source/IndBall2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndBall2.o source/IndBall2.cpp

${OBJECTDIR}/source/IndBox.o: source/IndBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndBox.o source/IndBox.cpp

${OBJECTDIR}/source/IndPos.o: source/IndPos.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndPos.o source/IndPos.cpp

${OBJECTDIR}/source/IndProbSimplex.o: source/IndProbSimplex.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndProbSimplex.o source/IndProbSimplex.cpp

${OBJECTDIR}/source/IndSOC.o: source/IndSOC.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndSOC.o source/IndSOC.cpp

${OBJECTDIR}/source/LBFGSBuffer.o: source/LBFGSBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LBFGSBuffer.o source/LBFGSBuffer.cpp

${OBJECTDIR}/source/LDLFactorization.o: source/LDLFactorization.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LDLFactorization.o source/LDLFactorization.cpp

${OBJECTDIR}/source/LQCost.o: source/LQCost.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LQCost.o source/LQCost.cpp

${OBJECTDIR}/source/LinOpSolver.o: source/LinOpSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LinOpSolver.o source/LinOpSolver.cpp

${OBJECTDIR}/source/LinSysSolver.o: source/LinSysSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LinSysSolver.o source/LinSysSolver.cpp

${OBJECTDIR}/source/LinearOperator.o: source/LinearOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LinearOperator.o source/LinearOperator.cpp

${OBJECTDIR}/source/LogLogisticLoss.o: source/LogLogisticLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LogLogisticLoss.o source/LogLogisticLoss.cpp

${OBJECTDIR}/source/Matrix.o: source/Matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Matrix.o source/Matrix.cpp

${OBJECTDIR}/source/MatrixFactory.o: source/MatrixFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixFactory.o source/MatrixFactory.cpp

${OBJECTDIR}/source/MatrixOperator.o: source/MatrixOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixOperator.o source/MatrixOperator.cpp

${OBJECTDIR}/source/MatrixSolver.o: source/MatrixSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixSolver.o source/MatrixSolver.cpp

${OBJECTDIR}/source/MatrixWriter.o: source/MatrixWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixWriter.o source/MatrixWriter.cpp

${OBJECTDIR}/source/Norm.o: source/Norm.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Norm.o source/Norm.cpp

${OBJECTDIR}/source/Norm1.o: source/Norm1.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Norm1.o source/Norm1.cpp

${OBJECTDIR}/source/Norm2.o: source/Norm2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Norm2.o source/Norm2.cpp

${OBJECTDIR}/source/OpAdjoint.o: source/OpAdjoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpAdjoint.o source/OpAdjoint.cpp

${OBJECTDIR}/source/OpComposition.o: source/OpComposition.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpComposition.o source/OpComposition.cpp

${OBJECTDIR}/source/OpDCT2.o: source/OpDCT2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpDCT2.o source/OpDCT2.cpp

${OBJECTDIR}/source/OpDCT3.o: source/OpDCT3.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpDCT3.o source/OpDCT3.cpp

${OBJECTDIR}/source/OpGradient.o: source/OpGradient.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpGradient.o source/OpGradient.cpp

${OBJECTDIR}/source/OpGradient2D.o: source/OpGradient2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpGradient2D.o source/OpGradient2D.cpp

${OBJECTDIR}/source/OpLTI.o: source/OpLTI.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpLTI.o source/OpLTI.cpp

${OBJECTDIR}/source/OpLinearCombination.o: source/OpLinearCombination.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpLinearCombination.o source/OpLinearCombination.cpp

${OBJECTDIR}/source/OpReverseVector.o: source/OpReverseVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpReverseVector.o source/OpReverseVector.cpp

${OBJECTDIR}/source/OpSum.o: source/OpSum.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpSum.o source/OpSum.cpp

${OBJECTDIR}/source/Properties.o: source/Properties.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Properties.o source/Properties.cpp

${OBJECTDIR}/source/QuadOverAffine.o: source/QuadOverAffine.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadOverAffine.o source/QuadOverAffine.cpp

${OBJECTDIR}/source/Quadratic.o: source/Quadratic.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Quadratic.o source/Quadratic.cpp

${OBJECTDIR}/source/QuadraticLoss.o: source/QuadraticLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadraticLoss.o source/QuadraticLoss.cpp

${OBJECTDIR}/source/QuadraticLossOverAffine.o: source/QuadraticLossOverAffine.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadraticLossOverAffine.o source/QuadraticLossOverAffine.cpp

${OBJECTDIR}/source/QuadraticOperator.o: source/QuadraticOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadraticOperator.o source/QuadraticOperator.cpp

${OBJECTDIR}/source/S_LDLFactorization.o: source/S_LDLFactorization.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/S_LDLFactorization.o source/S_LDLFactorization.cpp

${OBJECTDIR}/source/SeparableSum.o: source/SeparableSum.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SeparableSum.o source/SeparableSum.cpp

${OBJECTDIR}/source/SeparableSumOrdered.o: source/SeparableSumOrdered.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SeparableSumOrdered.o source/SeparableSumOrdered.cpp

${OBJECTDIR}/source/SumOfNorm2.o: source/SumOfNorm2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SumOfNorm2.o source/SumOfNorm2.cpp

${OBJECTDIR}/source/main.o: source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main.o source/main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f1: ${TESTDIR}/source/tests/TestCGSolver.o ${TESTDIR}/source/tests/TestCGSolverRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f2: ${TESTDIR}/source/tests/TestCholesky.o ${TESTDIR}/source/tests/TestCholeskyRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/source/tests/TestConjugateFunction.o ${TESTDIR}/source/tests/TestConjugateFunctionRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/source/tests/TestDistanceToBall2.o ${TESTDIR}/source/tests/TestDistanceToBall2Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f5: ${TESTDIR}/source/tests/TestDistanceToBox.o ${TESTDIR}/source/tests/TestDistanceToBoxRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f6: ${TESTDIR}/source/tests/TestElasticNet.o ${TESTDIR}/source/tests/TestElasticNetRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f7: ${TESTDIR}/source/tests/TestFBCache.o ${TESTDIR}/source/tests/TestFBCacheRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f22: ${TESTDIR}/source/tests/TestFBProblem.o ${TESTDIR}/source/tests/TestFBProblemRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f22 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f8: ${TESTDIR}/source/tests/TestFBSplitting.o ${TESTDIR}/source/tests/TestFBSplittingRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f9: ${TESTDIR}/source/tests/TestFBSplittingFast.o ${TESTDIR}/source/tests/TestFBSplittingFastRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f10: ${TESTDIR}/source/tests/TestFunctionOntologicalClass.o ${TESTDIR}/source/tests/TestFunctionOntologicalClassRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f11: ${TESTDIR}/source/tests/TestFunctionOntologyRegistry.o ${TESTDIR}/source/tests/TestFunctionOntologyRegistryRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f11 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f12: ${TESTDIR}/source/tests/TestHingeLoss.o ${TESTDIR}/source/tests/TestHingeLossRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f12 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f13: ${TESTDIR}/source/tests/TestHuber.o ${TESTDIR}/source/tests/TestHuberRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f13 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f14: ${TESTDIR}/source/tests/TestIndBall2.o ${TESTDIR}/source/tests/TestIndBall2Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f14 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f15: ${TESTDIR}/source/tests/TestIndBox.o ${TESTDIR}/source/tests/TestIndBoxRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f15 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f16: ${TESTDIR}/source/tests/TestIndPos.o ${TESTDIR}/source/tests/TestIndPosRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f16 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f17: ${TESTDIR}/source/tests/TestIndProbSimplex.o ${TESTDIR}/source/tests/TestIndProbSimplexRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f17 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f18: ${TESTDIR}/source/tests/TestIndSOC.o ${TESTDIR}/source/tests/TestIndSOCRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f18 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f19: ${TESTDIR}/source/tests/TestLasso.o ${TESTDIR}/source/tests/TestLassoRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f19 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f20: ${TESTDIR}/source/tests/TestLBFGSBuffer.o ${TESTDIR}/source/tests/TestLBFGSBufferRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f20 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f21: ${TESTDIR}/source/tests/TestLDL.o ${TESTDIR}/source/tests/TestLDLRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f21 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f23: ${TESTDIR}/source/tests/TestLogLogisticLoss.o ${TESTDIR}/source/tests/TestLogLogisticLossRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f23 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f24: ${TESTDIR}/source/tests/TestMatrix.o ${TESTDIR}/source/tests/TestMatrixRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f24 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f25: ${TESTDIR}/source/tests/TestMatrixExtras.o ${TESTDIR}/source/tests/TestMatrixExtrasRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f25 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f27: ${TESTDIR}/source/tests/TestMatrixFactory.o ${TESTDIR}/source/tests/TestMatrixFactoryRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f27 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f28: ${TESTDIR}/source/tests/TestMatrixOperator.o ${TESTDIR}/source/tests/TestMatrixOperatorRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f28 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f29: ${TESTDIR}/source/tests/TestNorm1.o ${TESTDIR}/source/tests/TestNorm1Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f29 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f30: ${TESTDIR}/source/tests/TestNorm2.o ${TESTDIR}/source/tests/TestNorm2Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f30 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f31: ${TESTDIR}/source/tests/TestOntRegistry.o ${TESTDIR}/source/tests/TestOntRegistryRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f31 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f32: ${TESTDIR}/source/tests/TestOpAdjoint.o ${TESTDIR}/source/tests/TestOpAdjointRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f32 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f33: ${TESTDIR}/source/tests/TestOpComposition.o ${TESTDIR}/source/tests/TestOpCompositionRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f33 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f34: ${TESTDIR}/source/tests/TestOpDCT2.o ${TESTDIR}/source/tests/TestOpDCT2Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f34 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f35: ${TESTDIR}/source/tests/TestOpDCT3.o ${TESTDIR}/source/tests/TestOpDCT3Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f35 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f36: ${TESTDIR}/source/tests/TestOpGradient.o ${TESTDIR}/source/tests/TestOpGradientRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f36 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f37: ${TESTDIR}/source/tests/TestOpReverseVector.o ${TESTDIR}/source/tests/TestOpReverseVectorRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f37 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f38: ${TESTDIR}/source/tests/TestProperties.o ${TESTDIR}/source/tests/TestPropertiesRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f38 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f39: ${TESTDIR}/source/tests/TestQuadOverAffine.o ${TESTDIR}/source/tests/TestQuadOverAffineRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f39 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f40: ${TESTDIR}/source/tests/TestQuadratic.o ${TESTDIR}/source/tests/TestQuadraticRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f40 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f41: ${TESTDIR}/source/tests/TestQuadraticLoss.o ${TESTDIR}/source/tests/TestQuadraticLossRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f41 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f42: ${TESTDIR}/source/tests/TestQuadraticLossOverAffine.o ${TESTDIR}/source/tests/TestQuadraticLossOverAffineRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f42 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f43: ${TESTDIR}/source/tests/TestQuadraticOperator.o ${TESTDIR}/source/tests/TestQuadraticOperatorRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f43 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f44: ${TESTDIR}/source/tests/TestSeparableSum.o ${TESTDIR}/source/tests/TestSeparableSumRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f44 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f26: ${TESTDIR}/source/tests/TestSLDL.o ${TESTDIR}/source/tests/TestSLDLRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f26 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f45: ${TESTDIR}/source/tests/TestSumOfNorm2.o ${TESTDIR}/source/tests/TestSumOfNorm2Runner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f45 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   


${TESTDIR}/source/tests/TestCGSolver.o: source/tests/TestCGSolver.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestCGSolver.o source/tests/TestCGSolver.cpp


${TESTDIR}/source/tests/TestCGSolverRunner.o: source/tests/TestCGSolverRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestCGSolverRunner.o source/tests/TestCGSolverRunner.cpp


${TESTDIR}/source/tests/TestCholesky.o: source/tests/TestCholesky.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestCholesky.o source/tests/TestCholesky.cpp


${TESTDIR}/source/tests/TestCholeskyRunner.o: source/tests/TestCholeskyRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestCholeskyRunner.o source/tests/TestCholeskyRunner.cpp


${TESTDIR}/source/tests/TestConjugateFunction.o: source/tests/TestConjugateFunction.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestConjugateFunction.o source/tests/TestConjugateFunction.cpp


${TESTDIR}/source/tests/TestConjugateFunctionRunner.o: source/tests/TestConjugateFunctionRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestConjugateFunctionRunner.o source/tests/TestConjugateFunctionRunner.cpp


${TESTDIR}/source/tests/TestDistanceToBall2.o: source/tests/TestDistanceToBall2.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestDistanceToBall2.o source/tests/TestDistanceToBall2.cpp


${TESTDIR}/source/tests/TestDistanceToBall2Runner.o: source/tests/TestDistanceToBall2Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestDistanceToBall2Runner.o source/tests/TestDistanceToBall2Runner.cpp


${TESTDIR}/source/tests/TestDistanceToBox.o: source/tests/TestDistanceToBox.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestDistanceToBox.o source/tests/TestDistanceToBox.cpp


${TESTDIR}/source/tests/TestDistanceToBoxRunner.o: source/tests/TestDistanceToBoxRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestDistanceToBoxRunner.o source/tests/TestDistanceToBoxRunner.cpp


${TESTDIR}/source/tests/TestElasticNet.o: source/tests/TestElasticNet.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestElasticNet.o source/tests/TestElasticNet.cpp


${TESTDIR}/source/tests/TestElasticNetRunner.o: source/tests/TestElasticNetRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestElasticNetRunner.o source/tests/TestElasticNetRunner.cpp


${TESTDIR}/source/tests/TestFBCache.o: source/tests/TestFBCache.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBCache.o source/tests/TestFBCache.cpp


${TESTDIR}/source/tests/TestFBCacheRunner.o: source/tests/TestFBCacheRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBCacheRunner.o source/tests/TestFBCacheRunner.cpp


${TESTDIR}/source/tests/TestFBProblem.o: source/tests/TestFBProblem.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBProblem.o source/tests/TestFBProblem.cpp


${TESTDIR}/source/tests/TestFBProblemRunner.o: source/tests/TestFBProblemRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBProblemRunner.o source/tests/TestFBProblemRunner.cpp


${TESTDIR}/source/tests/TestFBSplitting.o: source/tests/TestFBSplitting.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBSplitting.o source/tests/TestFBSplitting.cpp


${TESTDIR}/source/tests/TestFBSplittingRunner.o: source/tests/TestFBSplittingRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBSplittingRunner.o source/tests/TestFBSplittingRunner.cpp


${TESTDIR}/source/tests/TestFBSplittingFast.o: source/tests/TestFBSplittingFast.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBSplittingFast.o source/tests/TestFBSplittingFast.cpp


${TESTDIR}/source/tests/TestFBSplittingFastRunner.o: source/tests/TestFBSplittingFastRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFBSplittingFastRunner.o source/tests/TestFBSplittingFastRunner.cpp


${TESTDIR}/source/tests/TestFunctionOntologicalClass.o: source/tests/TestFunctionOntologicalClass.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFunctionOntologicalClass.o source/tests/TestFunctionOntologicalClass.cpp


${TESTDIR}/source/tests/TestFunctionOntologicalClassRunner.o: source/tests/TestFunctionOntologicalClassRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFunctionOntologicalClassRunner.o source/tests/TestFunctionOntologicalClassRunner.cpp


${TESTDIR}/source/tests/TestFunctionOntologyRegistry.o: source/tests/TestFunctionOntologyRegistry.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFunctionOntologyRegistry.o source/tests/TestFunctionOntologyRegistry.cpp


${TESTDIR}/source/tests/TestFunctionOntologyRegistryRunner.o: source/tests/TestFunctionOntologyRegistryRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestFunctionOntologyRegistryRunner.o source/tests/TestFunctionOntologyRegistryRunner.cpp


${TESTDIR}/source/tests/TestHingeLoss.o: source/tests/TestHingeLoss.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestHingeLoss.o source/tests/TestHingeLoss.cpp


${TESTDIR}/source/tests/TestHingeLossRunner.o: source/tests/TestHingeLossRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestHingeLossRunner.o source/tests/TestHingeLossRunner.cpp


${TESTDIR}/source/tests/TestHuber.o: source/tests/TestHuber.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestHuber.o source/tests/TestHuber.cpp


${TESTDIR}/source/tests/TestHuberRunner.o: source/tests/TestHuberRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestHuberRunner.o source/tests/TestHuberRunner.cpp


${TESTDIR}/source/tests/TestIndBall2.o: source/tests/TestIndBall2.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndBall2.o source/tests/TestIndBall2.cpp


${TESTDIR}/source/tests/TestIndBall2Runner.o: source/tests/TestIndBall2Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndBall2Runner.o source/tests/TestIndBall2Runner.cpp


${TESTDIR}/source/tests/TestIndBox.o: source/tests/TestIndBox.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndBox.o source/tests/TestIndBox.cpp


${TESTDIR}/source/tests/TestIndBoxRunner.o: source/tests/TestIndBoxRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndBoxRunner.o source/tests/TestIndBoxRunner.cpp


${TESTDIR}/source/tests/TestIndPos.o: source/tests/TestIndPos.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndPos.o source/tests/TestIndPos.cpp


${TESTDIR}/source/tests/TestIndPosRunner.o: source/tests/TestIndPosRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndPosRunner.o source/tests/TestIndPosRunner.cpp


${TESTDIR}/source/tests/TestIndProbSimplex.o: source/tests/TestIndProbSimplex.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndProbSimplex.o source/tests/TestIndProbSimplex.cpp


${TESTDIR}/source/tests/TestIndProbSimplexRunner.o: source/tests/TestIndProbSimplexRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndProbSimplexRunner.o source/tests/TestIndProbSimplexRunner.cpp


${TESTDIR}/source/tests/TestIndSOC.o: source/tests/TestIndSOC.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndSOC.o source/tests/TestIndSOC.cpp


${TESTDIR}/source/tests/TestIndSOCRunner.o: source/tests/TestIndSOCRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestIndSOCRunner.o source/tests/TestIndSOCRunner.cpp


${TESTDIR}/source/tests/TestLasso.o: source/tests/TestLasso.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLasso.o source/tests/TestLasso.cpp


${TESTDIR}/source/tests/TestLassoRunner.o: source/tests/TestLassoRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLassoRunner.o source/tests/TestLassoRunner.cpp


${TESTDIR}/source/tests/TestLBFGSBuffer.o: source/tests/TestLBFGSBuffer.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLBFGSBuffer.o source/tests/TestLBFGSBuffer.cpp


${TESTDIR}/source/tests/TestLBFGSBufferRunner.o: source/tests/TestLBFGSBufferRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLBFGSBufferRunner.o source/tests/TestLBFGSBufferRunner.cpp


${TESTDIR}/source/tests/TestLDL.o: source/tests/TestLDL.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLDL.o source/tests/TestLDL.cpp


${TESTDIR}/source/tests/TestLDLRunner.o: source/tests/TestLDLRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLDLRunner.o source/tests/TestLDLRunner.cpp


${TESTDIR}/source/tests/TestLogLogisticLoss.o: source/tests/TestLogLogisticLoss.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLogLogisticLoss.o source/tests/TestLogLogisticLoss.cpp


${TESTDIR}/source/tests/TestLogLogisticLossRunner.o: source/tests/TestLogLogisticLossRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestLogLogisticLossRunner.o source/tests/TestLogLogisticLossRunner.cpp


${TESTDIR}/source/tests/TestMatrix.o: source/tests/TestMatrix.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrix.o source/tests/TestMatrix.cpp


${TESTDIR}/source/tests/TestMatrixRunner.o: source/tests/TestMatrixRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixRunner.o source/tests/TestMatrixRunner.cpp


${TESTDIR}/source/tests/TestMatrixExtras.o: source/tests/TestMatrixExtras.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixExtras.o source/tests/TestMatrixExtras.cpp


${TESTDIR}/source/tests/TestMatrixExtrasRunner.o: source/tests/TestMatrixExtrasRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixExtrasRunner.o source/tests/TestMatrixExtrasRunner.cpp


${TESTDIR}/source/tests/TestMatrixFactory.o: source/tests/TestMatrixFactory.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixFactory.o source/tests/TestMatrixFactory.cpp


${TESTDIR}/source/tests/TestMatrixFactoryRunner.o: source/tests/TestMatrixFactoryRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixFactoryRunner.o source/tests/TestMatrixFactoryRunner.cpp


${TESTDIR}/source/tests/TestMatrixOperator.o: source/tests/TestMatrixOperator.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixOperator.o source/tests/TestMatrixOperator.cpp


${TESTDIR}/source/tests/TestMatrixOperatorRunner.o: source/tests/TestMatrixOperatorRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestMatrixOperatorRunner.o source/tests/TestMatrixOperatorRunner.cpp


${TESTDIR}/source/tests/TestNorm1.o: source/tests/TestNorm1.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestNorm1.o source/tests/TestNorm1.cpp


${TESTDIR}/source/tests/TestNorm1Runner.o: source/tests/TestNorm1Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestNorm1Runner.o source/tests/TestNorm1Runner.cpp


${TESTDIR}/source/tests/TestNorm2.o: source/tests/TestNorm2.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestNorm2.o source/tests/TestNorm2.cpp


${TESTDIR}/source/tests/TestNorm2Runner.o: source/tests/TestNorm2Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestNorm2Runner.o source/tests/TestNorm2Runner.cpp


${TESTDIR}/source/tests/TestOntRegistry.o: source/tests/TestOntRegistry.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOntRegistry.o source/tests/TestOntRegistry.cpp


${TESTDIR}/source/tests/TestOntRegistryRunner.o: source/tests/TestOntRegistryRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOntRegistryRunner.o source/tests/TestOntRegistryRunner.cpp


${TESTDIR}/source/tests/TestOpAdjoint.o: source/tests/TestOpAdjoint.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpAdjoint.o source/tests/TestOpAdjoint.cpp


${TESTDIR}/source/tests/TestOpAdjointRunner.o: source/tests/TestOpAdjointRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpAdjointRunner.o source/tests/TestOpAdjointRunner.cpp


${TESTDIR}/source/tests/TestOpComposition.o: source/tests/TestOpComposition.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpComposition.o source/tests/TestOpComposition.cpp


${TESTDIR}/source/tests/TestOpCompositionRunner.o: source/tests/TestOpCompositionRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpCompositionRunner.o source/tests/TestOpCompositionRunner.cpp


${TESTDIR}/source/tests/TestOpDCT2.o: source/tests/TestOpDCT2.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpDCT2.o source/tests/TestOpDCT2.cpp


${TESTDIR}/source/tests/TestOpDCT2Runner.o: source/tests/TestOpDCT2Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpDCT2Runner.o source/tests/TestOpDCT2Runner.cpp


${TESTDIR}/source/tests/TestOpDCT3.o: source/tests/TestOpDCT3.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpDCT3.o source/tests/TestOpDCT3.cpp


${TESTDIR}/source/tests/TestOpDCT3Runner.o: source/tests/TestOpDCT3Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpDCT3Runner.o source/tests/TestOpDCT3Runner.cpp


${TESTDIR}/source/tests/TestOpGradient.o: source/tests/TestOpGradient.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpGradient.o source/tests/TestOpGradient.cpp


${TESTDIR}/source/tests/TestOpGradientRunner.o: source/tests/TestOpGradientRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpGradientRunner.o source/tests/TestOpGradientRunner.cpp


${TESTDIR}/source/tests/TestOpReverseVector.o: source/tests/TestOpReverseVector.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpReverseVector.o source/tests/TestOpReverseVector.cpp


${TESTDIR}/source/tests/TestOpReverseVectorRunner.o: source/tests/TestOpReverseVectorRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestOpReverseVectorRunner.o source/tests/TestOpReverseVectorRunner.cpp


${TESTDIR}/source/tests/TestProperties.o: source/tests/TestProperties.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestProperties.o source/tests/TestProperties.cpp


${TESTDIR}/source/tests/TestPropertiesRunner.o: source/tests/TestPropertiesRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestPropertiesRunner.o source/tests/TestPropertiesRunner.cpp


${TESTDIR}/source/tests/TestQuadOverAffine.o: source/tests/TestQuadOverAffine.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadOverAffine.o source/tests/TestQuadOverAffine.cpp


${TESTDIR}/source/tests/TestQuadOverAffineRunner.o: source/tests/TestQuadOverAffineRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadOverAffineRunner.o source/tests/TestQuadOverAffineRunner.cpp


${TESTDIR}/source/tests/TestQuadratic.o: source/tests/TestQuadratic.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadratic.o source/tests/TestQuadratic.cpp


${TESTDIR}/source/tests/TestQuadraticRunner.o: source/tests/TestQuadraticRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticRunner.o source/tests/TestQuadraticRunner.cpp


${TESTDIR}/source/tests/TestQuadraticLoss.o: source/tests/TestQuadraticLoss.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticLoss.o source/tests/TestQuadraticLoss.cpp


${TESTDIR}/source/tests/TestQuadraticLossRunner.o: source/tests/TestQuadraticLossRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticLossRunner.o source/tests/TestQuadraticLossRunner.cpp


${TESTDIR}/source/tests/TestQuadraticLossOverAffine.o: source/tests/TestQuadraticLossOverAffine.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticLossOverAffine.o source/tests/TestQuadraticLossOverAffine.cpp


${TESTDIR}/source/tests/TestQuadraticLossOverAffineRunner.o: source/tests/TestQuadraticLossOverAffineRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticLossOverAffineRunner.o source/tests/TestQuadraticLossOverAffineRunner.cpp


${TESTDIR}/source/tests/TestQuadraticOperator.o: source/tests/TestQuadraticOperator.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticOperator.o source/tests/TestQuadraticOperator.cpp


${TESTDIR}/source/tests/TestQuadraticOperatorRunner.o: source/tests/TestQuadraticOperatorRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestQuadraticOperatorRunner.o source/tests/TestQuadraticOperatorRunner.cpp


${TESTDIR}/source/tests/TestSeparableSum.o: source/tests/TestSeparableSum.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestSeparableSum.o source/tests/TestSeparableSum.cpp


${TESTDIR}/source/tests/TestSeparableSumRunner.o: source/tests/TestSeparableSumRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestSeparableSumRunner.o source/tests/TestSeparableSumRunner.cpp


${TESTDIR}/source/tests/TestSLDL.o: source/tests/TestSLDL.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestSLDL.o source/tests/TestSLDL.cpp


${TESTDIR}/source/tests/TestSLDLRunner.o: source/tests/TestSLDLRunner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestSLDLRunner.o source/tests/TestSLDLRunner.cpp


${TESTDIR}/source/tests/TestSumOfNorm2.o: source/tests/TestSumOfNorm2.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestSumOfNorm2.o source/tests/TestSumOfNorm2.cpp


${TESTDIR}/source/tests/TestSumOfNorm2Runner.o: source/tests/TestSumOfNorm2Runner.cpp 
	${MKDIR} -p ${TESTDIR}/source/tests
	${RM} "$@.d"
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF "$@.d" -o ${TESTDIR}/source/tests/TestSumOfNorm2Runner.o source/tests/TestSumOfNorm2Runner.cpp


${OBJECTDIR}/examples/matop_example_nomain.o: ${OBJECTDIR}/examples/matop_example.o examples/matop_example.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	@NMOUTPUT=`${NM} ${OBJECTDIR}/examples/matop_example.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/matop_example_nomain.o examples/matop_example.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/examples/matop_example.o ${OBJECTDIR}/examples/matop_example_nomain.o;\
	fi

${OBJECTDIR}/examples/matrix_example_nomain.o: ${OBJECTDIR}/examples/matrix_example.o examples/matrix_example.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	@NMOUTPUT=`${NM} ${OBJECTDIR}/examples/matrix_example.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/matrix_example_nomain.o examples/matrix_example.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/examples/matrix_example.o ${OBJECTDIR}/examples/matrix_example_nomain.o;\
	fi

${OBJECTDIR}/examples/qp_box_nomain.o: ${OBJECTDIR}/examples/qp_box.o examples/qp_box.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	@NMOUTPUT=`${NM} ${OBJECTDIR}/examples/qp_box.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/qp_box_nomain.o examples/qp_box.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/examples/qp_box.o ${OBJECTDIR}/examples/qp_box_nomain.o;\
	fi

${OBJECTDIR}/examples/shallow_example_nomain.o: ${OBJECTDIR}/examples/shallow_example.o examples/shallow_example.cpp 
	${MKDIR} -p ${OBJECTDIR}/examples
	@NMOUTPUT=`${NM} ${OBJECTDIR}/examples/shallow_example.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/examples/shallow_example_nomain.o examples/shallow_example.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/examples/shallow_example.o ${OBJECTDIR}/examples/shallow_example_nomain.o;\
	fi

${OBJECTDIR}/source/CGSolver_nomain.o: ${OBJECTDIR}/source/CGSolver.o source/CGSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/CGSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/CGSolver_nomain.o source/CGSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/CGSolver.o ${OBJECTDIR}/source/CGSolver_nomain.o;\
	fi

${OBJECTDIR}/source/CholeskyFactorization_nomain.o: ${OBJECTDIR}/source/CholeskyFactorization.o source/CholeskyFactorization.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/CholeskyFactorization.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/CholeskyFactorization_nomain.o source/CholeskyFactorization.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/CholeskyFactorization.o ${OBJECTDIR}/source/CholeskyFactorization_nomain.o;\
	fi

${OBJECTDIR}/source/ConjugateFunction_nomain.o: ${OBJECTDIR}/source/ConjugateFunction.o source/ConjugateFunction.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/ConjugateFunction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ConjugateFunction_nomain.o source/ConjugateFunction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/ConjugateFunction.o ${OBJECTDIR}/source/ConjugateFunction_nomain.o;\
	fi

${OBJECTDIR}/source/DistanceToBall2_nomain.o: ${OBJECTDIR}/source/DistanceToBall2.o source/DistanceToBall2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/DistanceToBall2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/DistanceToBall2_nomain.o source/DistanceToBall2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/DistanceToBall2.o ${OBJECTDIR}/source/DistanceToBall2_nomain.o;\
	fi

${OBJECTDIR}/source/DistanceToBox_nomain.o: ${OBJECTDIR}/source/DistanceToBox.o source/DistanceToBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/DistanceToBox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/DistanceToBox_nomain.o source/DistanceToBox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/DistanceToBox.o ${OBJECTDIR}/source/DistanceToBox_nomain.o;\
	fi

${OBJECTDIR}/source/ElasticNet_nomain.o: ${OBJECTDIR}/source/ElasticNet.o source/ElasticNet.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/ElasticNet.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ElasticNet_nomain.o source/ElasticNet.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/ElasticNet.o ${OBJECTDIR}/source/ElasticNet_nomain.o;\
	fi

${OBJECTDIR}/source/FBCache_nomain.o: ${OBJECTDIR}/source/FBCache.o source/FBCache.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FBCache.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBCache_nomain.o source/FBCache.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FBCache.o ${OBJECTDIR}/source/FBCache_nomain.o;\
	fi

${OBJECTDIR}/source/FBProblem_nomain.o: ${OBJECTDIR}/source/FBProblem.o source/FBProblem.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FBProblem.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBProblem_nomain.o source/FBProblem.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FBProblem.o ${OBJECTDIR}/source/FBProblem_nomain.o;\
	fi

${OBJECTDIR}/source/FBSplitting_nomain.o: ${OBJECTDIR}/source/FBSplitting.o source/FBSplitting.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FBSplitting.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBSplitting_nomain.o source/FBSplitting.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FBSplitting.o ${OBJECTDIR}/source/FBSplitting_nomain.o;\
	fi

${OBJECTDIR}/source/FBSplittingFast_nomain.o: ${OBJECTDIR}/source/FBSplittingFast.o source/FBSplittingFast.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FBSplittingFast.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBSplittingFast_nomain.o source/FBSplittingFast.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FBSplittingFast.o ${OBJECTDIR}/source/FBSplittingFast_nomain.o;\
	fi

${OBJECTDIR}/source/FBStopping_nomain.o: ${OBJECTDIR}/source/FBStopping.o source/FBStopping.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FBStopping.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBStopping_nomain.o source/FBStopping.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FBStopping.o ${OBJECTDIR}/source/FBStopping_nomain.o;\
	fi

${OBJECTDIR}/source/FBStoppingRelative_nomain.o: ${OBJECTDIR}/source/FBStoppingRelative.o source/FBStoppingRelative.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FBStoppingRelative.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FBStoppingRelative_nomain.o source/FBStoppingRelative.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FBStoppingRelative.o ${OBJECTDIR}/source/FBStoppingRelative_nomain.o;\
	fi

${OBJECTDIR}/source/FactoredSolver_nomain.o: ${OBJECTDIR}/source/FactoredSolver.o source/FactoredSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FactoredSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FactoredSolver_nomain.o source/FactoredSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FactoredSolver.o ${OBJECTDIR}/source/FactoredSolver_nomain.o;\
	fi

${OBJECTDIR}/source/ForBESUtils_nomain.o: ${OBJECTDIR}/source/ForBESUtils.o source/ForBESUtils.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/ForBESUtils.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/ForBESUtils_nomain.o source/ForBESUtils.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/ForBESUtils.o ${OBJECTDIR}/source/ForBESUtils_nomain.o;\
	fi

${OBJECTDIR}/source/Function_nomain.o: ${OBJECTDIR}/source/Function.o source/Function.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Function.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Function_nomain.o source/Function.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Function.o ${OBJECTDIR}/source/Function_nomain.o;\
	fi

${OBJECTDIR}/source/FunctionOntologicalClass_nomain.o: ${OBJECTDIR}/source/FunctionOntologicalClass.o source/FunctionOntologicalClass.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FunctionOntologicalClass.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FunctionOntologicalClass_nomain.o source/FunctionOntologicalClass.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FunctionOntologicalClass.o ${OBJECTDIR}/source/FunctionOntologicalClass_nomain.o;\
	fi

${OBJECTDIR}/source/FunctionOntologyRegistry_nomain.o: ${OBJECTDIR}/source/FunctionOntologyRegistry.o source/FunctionOntologyRegistry.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/FunctionOntologyRegistry.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/FunctionOntologyRegistry_nomain.o source/FunctionOntologyRegistry.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/FunctionOntologyRegistry.o ${OBJECTDIR}/source/FunctionOntologyRegistry_nomain.o;\
	fi

${OBJECTDIR}/source/HingeLoss_nomain.o: ${OBJECTDIR}/source/HingeLoss.o source/HingeLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/HingeLoss.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/HingeLoss_nomain.o source/HingeLoss.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/HingeLoss.o ${OBJECTDIR}/source/HingeLoss_nomain.o;\
	fi

${OBJECTDIR}/source/HuberLoss_nomain.o: ${OBJECTDIR}/source/HuberLoss.o source/HuberLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/HuberLoss.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/HuberLoss_nomain.o source/HuberLoss.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/HuberLoss.o ${OBJECTDIR}/source/HuberLoss_nomain.o;\
	fi

${OBJECTDIR}/source/IndBall2_nomain.o: ${OBJECTDIR}/source/IndBall2.o source/IndBall2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/IndBall2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndBall2_nomain.o source/IndBall2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/IndBall2.o ${OBJECTDIR}/source/IndBall2_nomain.o;\
	fi

${OBJECTDIR}/source/IndBox_nomain.o: ${OBJECTDIR}/source/IndBox.o source/IndBox.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/IndBox.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndBox_nomain.o source/IndBox.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/IndBox.o ${OBJECTDIR}/source/IndBox_nomain.o;\
	fi

${OBJECTDIR}/source/IndPos_nomain.o: ${OBJECTDIR}/source/IndPos.o source/IndPos.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/IndPos.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndPos_nomain.o source/IndPos.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/IndPos.o ${OBJECTDIR}/source/IndPos_nomain.o;\
	fi

${OBJECTDIR}/source/IndProbSimplex_nomain.o: ${OBJECTDIR}/source/IndProbSimplex.o source/IndProbSimplex.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/IndProbSimplex.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndProbSimplex_nomain.o source/IndProbSimplex.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/IndProbSimplex.o ${OBJECTDIR}/source/IndProbSimplex_nomain.o;\
	fi

${OBJECTDIR}/source/IndSOC_nomain.o: ${OBJECTDIR}/source/IndSOC.o source/IndSOC.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/IndSOC.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/IndSOC_nomain.o source/IndSOC.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/IndSOC.o ${OBJECTDIR}/source/IndSOC_nomain.o;\
	fi

${OBJECTDIR}/source/LBFGSBuffer_nomain.o: ${OBJECTDIR}/source/LBFGSBuffer.o source/LBFGSBuffer.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LBFGSBuffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LBFGSBuffer_nomain.o source/LBFGSBuffer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LBFGSBuffer.o ${OBJECTDIR}/source/LBFGSBuffer_nomain.o;\
	fi

${OBJECTDIR}/source/LDLFactorization_nomain.o: ${OBJECTDIR}/source/LDLFactorization.o source/LDLFactorization.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LDLFactorization.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LDLFactorization_nomain.o source/LDLFactorization.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LDLFactorization.o ${OBJECTDIR}/source/LDLFactorization_nomain.o;\
	fi

${OBJECTDIR}/source/LQCost_nomain.o: ${OBJECTDIR}/source/LQCost.o source/LQCost.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LQCost.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LQCost_nomain.o source/LQCost.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LQCost.o ${OBJECTDIR}/source/LQCost_nomain.o;\
	fi

${OBJECTDIR}/source/LinOpSolver_nomain.o: ${OBJECTDIR}/source/LinOpSolver.o source/LinOpSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LinOpSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LinOpSolver_nomain.o source/LinOpSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LinOpSolver.o ${OBJECTDIR}/source/LinOpSolver_nomain.o;\
	fi

${OBJECTDIR}/source/LinSysSolver_nomain.o: ${OBJECTDIR}/source/LinSysSolver.o source/LinSysSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LinSysSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LinSysSolver_nomain.o source/LinSysSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LinSysSolver.o ${OBJECTDIR}/source/LinSysSolver_nomain.o;\
	fi

${OBJECTDIR}/source/LinearOperator_nomain.o: ${OBJECTDIR}/source/LinearOperator.o source/LinearOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LinearOperator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LinearOperator_nomain.o source/LinearOperator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LinearOperator.o ${OBJECTDIR}/source/LinearOperator_nomain.o;\
	fi

${OBJECTDIR}/source/LogLogisticLoss_nomain.o: ${OBJECTDIR}/source/LogLogisticLoss.o source/LogLogisticLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/LogLogisticLoss.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/LogLogisticLoss_nomain.o source/LogLogisticLoss.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/LogLogisticLoss.o ${OBJECTDIR}/source/LogLogisticLoss_nomain.o;\
	fi

${OBJECTDIR}/source/Matrix_nomain.o: ${OBJECTDIR}/source/Matrix.o source/Matrix.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Matrix.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Matrix_nomain.o source/Matrix.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Matrix.o ${OBJECTDIR}/source/Matrix_nomain.o;\
	fi

${OBJECTDIR}/source/MatrixFactory_nomain.o: ${OBJECTDIR}/source/MatrixFactory.o source/MatrixFactory.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/MatrixFactory.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixFactory_nomain.o source/MatrixFactory.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/MatrixFactory.o ${OBJECTDIR}/source/MatrixFactory_nomain.o;\
	fi

${OBJECTDIR}/source/MatrixOperator_nomain.o: ${OBJECTDIR}/source/MatrixOperator.o source/MatrixOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/MatrixOperator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixOperator_nomain.o source/MatrixOperator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/MatrixOperator.o ${OBJECTDIR}/source/MatrixOperator_nomain.o;\
	fi

${OBJECTDIR}/source/MatrixSolver_nomain.o: ${OBJECTDIR}/source/MatrixSolver.o source/MatrixSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/MatrixSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixSolver_nomain.o source/MatrixSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/MatrixSolver.o ${OBJECTDIR}/source/MatrixSolver_nomain.o;\
	fi

${OBJECTDIR}/source/MatrixWriter_nomain.o: ${OBJECTDIR}/source/MatrixWriter.o source/MatrixWriter.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/MatrixWriter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/MatrixWriter_nomain.o source/MatrixWriter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/MatrixWriter.o ${OBJECTDIR}/source/MatrixWriter_nomain.o;\
	fi

${OBJECTDIR}/source/Norm_nomain.o: ${OBJECTDIR}/source/Norm.o source/Norm.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Norm.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Norm_nomain.o source/Norm.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Norm.o ${OBJECTDIR}/source/Norm_nomain.o;\
	fi

${OBJECTDIR}/source/Norm1_nomain.o: ${OBJECTDIR}/source/Norm1.o source/Norm1.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Norm1.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Norm1_nomain.o source/Norm1.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Norm1.o ${OBJECTDIR}/source/Norm1_nomain.o;\
	fi

${OBJECTDIR}/source/Norm2_nomain.o: ${OBJECTDIR}/source/Norm2.o source/Norm2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Norm2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Norm2_nomain.o source/Norm2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Norm2.o ${OBJECTDIR}/source/Norm2_nomain.o;\
	fi

${OBJECTDIR}/source/OpAdjoint_nomain.o: ${OBJECTDIR}/source/OpAdjoint.o source/OpAdjoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpAdjoint.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpAdjoint_nomain.o source/OpAdjoint.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpAdjoint.o ${OBJECTDIR}/source/OpAdjoint_nomain.o;\
	fi

${OBJECTDIR}/source/OpComposition_nomain.o: ${OBJECTDIR}/source/OpComposition.o source/OpComposition.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpComposition.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpComposition_nomain.o source/OpComposition.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpComposition.o ${OBJECTDIR}/source/OpComposition_nomain.o;\
	fi

${OBJECTDIR}/source/OpDCT2_nomain.o: ${OBJECTDIR}/source/OpDCT2.o source/OpDCT2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpDCT2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpDCT2_nomain.o source/OpDCT2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpDCT2.o ${OBJECTDIR}/source/OpDCT2_nomain.o;\
	fi

${OBJECTDIR}/source/OpDCT3_nomain.o: ${OBJECTDIR}/source/OpDCT3.o source/OpDCT3.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpDCT3.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpDCT3_nomain.o source/OpDCT3.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpDCT3.o ${OBJECTDIR}/source/OpDCT3_nomain.o;\
	fi

${OBJECTDIR}/source/OpGradient_nomain.o: ${OBJECTDIR}/source/OpGradient.o source/OpGradient.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpGradient.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpGradient_nomain.o source/OpGradient.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpGradient.o ${OBJECTDIR}/source/OpGradient_nomain.o;\
	fi

${OBJECTDIR}/source/OpGradient2D_nomain.o: ${OBJECTDIR}/source/OpGradient2D.o source/OpGradient2D.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpGradient2D.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpGradient2D_nomain.o source/OpGradient2D.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpGradient2D.o ${OBJECTDIR}/source/OpGradient2D_nomain.o;\
	fi

${OBJECTDIR}/source/OpLTI_nomain.o: ${OBJECTDIR}/source/OpLTI.o source/OpLTI.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpLTI.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpLTI_nomain.o source/OpLTI.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpLTI.o ${OBJECTDIR}/source/OpLTI_nomain.o;\
	fi

${OBJECTDIR}/source/OpLinearCombination_nomain.o: ${OBJECTDIR}/source/OpLinearCombination.o source/OpLinearCombination.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpLinearCombination.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpLinearCombination_nomain.o source/OpLinearCombination.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpLinearCombination.o ${OBJECTDIR}/source/OpLinearCombination_nomain.o;\
	fi

${OBJECTDIR}/source/OpReverseVector_nomain.o: ${OBJECTDIR}/source/OpReverseVector.o source/OpReverseVector.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpReverseVector.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpReverseVector_nomain.o source/OpReverseVector.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpReverseVector.o ${OBJECTDIR}/source/OpReverseVector_nomain.o;\
	fi

${OBJECTDIR}/source/OpSum_nomain.o: ${OBJECTDIR}/source/OpSum.o source/OpSum.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/OpSum.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/OpSum_nomain.o source/OpSum.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/OpSum.o ${OBJECTDIR}/source/OpSum_nomain.o;\
	fi

${OBJECTDIR}/source/Properties_nomain.o: ${OBJECTDIR}/source/Properties.o source/Properties.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Properties.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Properties_nomain.o source/Properties.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Properties.o ${OBJECTDIR}/source/Properties_nomain.o;\
	fi

${OBJECTDIR}/source/QuadOverAffine_nomain.o: ${OBJECTDIR}/source/QuadOverAffine.o source/QuadOverAffine.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/QuadOverAffine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadOverAffine_nomain.o source/QuadOverAffine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/QuadOverAffine.o ${OBJECTDIR}/source/QuadOverAffine_nomain.o;\
	fi

${OBJECTDIR}/source/Quadratic_nomain.o: ${OBJECTDIR}/source/Quadratic.o source/Quadratic.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/Quadratic.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/Quadratic_nomain.o source/Quadratic.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/Quadratic.o ${OBJECTDIR}/source/Quadratic_nomain.o;\
	fi

${OBJECTDIR}/source/QuadraticLoss_nomain.o: ${OBJECTDIR}/source/QuadraticLoss.o source/QuadraticLoss.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/QuadraticLoss.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadraticLoss_nomain.o source/QuadraticLoss.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/QuadraticLoss.o ${OBJECTDIR}/source/QuadraticLoss_nomain.o;\
	fi

${OBJECTDIR}/source/QuadraticLossOverAffine_nomain.o: ${OBJECTDIR}/source/QuadraticLossOverAffine.o source/QuadraticLossOverAffine.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/QuadraticLossOverAffine.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadraticLossOverAffine_nomain.o source/QuadraticLossOverAffine.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/QuadraticLossOverAffine.o ${OBJECTDIR}/source/QuadraticLossOverAffine_nomain.o;\
	fi

${OBJECTDIR}/source/QuadraticOperator_nomain.o: ${OBJECTDIR}/source/QuadraticOperator.o source/QuadraticOperator.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/QuadraticOperator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/QuadraticOperator_nomain.o source/QuadraticOperator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/QuadraticOperator.o ${OBJECTDIR}/source/QuadraticOperator_nomain.o;\
	fi

${OBJECTDIR}/source/S_LDLFactorization_nomain.o: ${OBJECTDIR}/source/S_LDLFactorization.o source/S_LDLFactorization.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/S_LDLFactorization.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/S_LDLFactorization_nomain.o source/S_LDLFactorization.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/S_LDLFactorization.o ${OBJECTDIR}/source/S_LDLFactorization_nomain.o;\
	fi

${OBJECTDIR}/source/SeparableSum_nomain.o: ${OBJECTDIR}/source/SeparableSum.o source/SeparableSum.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/SeparableSum.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SeparableSum_nomain.o source/SeparableSum.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/SeparableSum.o ${OBJECTDIR}/source/SeparableSum_nomain.o;\
	fi

${OBJECTDIR}/source/SeparableSumOrdered_nomain.o: ${OBJECTDIR}/source/SeparableSumOrdered.o source/SeparableSumOrdered.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/SeparableSumOrdered.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SeparableSumOrdered_nomain.o source/SeparableSumOrdered.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/SeparableSumOrdered.o ${OBJECTDIR}/source/SeparableSumOrdered_nomain.o;\
	fi

${OBJECTDIR}/source/SumOfNorm2_nomain.o: ${OBJECTDIR}/source/SumOfNorm2.o source/SumOfNorm2.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/SumOfNorm2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/SumOfNorm2_nomain.o source/SumOfNorm2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/SumOfNorm2.o ${OBJECTDIR}/source/SumOfNorm2_nomain.o;\
	fi

${OBJECTDIR}/source/main_nomain.o: ${OBJECTDIR}/source/main.o source/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/source
	@NMOUTPUT=`${NM} ${OBJECTDIR}/source/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/source/main_nomain.o source/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/source/main.o ${OBJECTDIR}/source/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f22 || true; \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f11 || true; \
	    ${TESTDIR}/TestFiles/f12 || true; \
	    ${TESTDIR}/TestFiles/f13 || true; \
	    ${TESTDIR}/TestFiles/f14 || true; \
	    ${TESTDIR}/TestFiles/f15 || true; \
	    ${TESTDIR}/TestFiles/f16 || true; \
	    ${TESTDIR}/TestFiles/f17 || true; \
	    ${TESTDIR}/TestFiles/f18 || true; \
	    ${TESTDIR}/TestFiles/f19 || true; \
	    ${TESTDIR}/TestFiles/f20 || true; \
	    ${TESTDIR}/TestFiles/f21 || true; \
	    ${TESTDIR}/TestFiles/f23 || true; \
	    ${TESTDIR}/TestFiles/f24 || true; \
	    ${TESTDIR}/TestFiles/f25 || true; \
	    ${TESTDIR}/TestFiles/f27 || true; \
	    ${TESTDIR}/TestFiles/f28 || true; \
	    ${TESTDIR}/TestFiles/f29 || true; \
	    ${TESTDIR}/TestFiles/f30 || true; \
	    ${TESTDIR}/TestFiles/f31 || true; \
	    ${TESTDIR}/TestFiles/f32 || true; \
	    ${TESTDIR}/TestFiles/f33 || true; \
	    ${TESTDIR}/TestFiles/f34 || true; \
	    ${TESTDIR}/TestFiles/f35 || true; \
	    ${TESTDIR}/TestFiles/f36 || true; \
	    ${TESTDIR}/TestFiles/f37 || true; \
	    ${TESTDIR}/TestFiles/f38 || true; \
	    ${TESTDIR}/TestFiles/f39 || true; \
	    ${TESTDIR}/TestFiles/f40 || true; \
	    ${TESTDIR}/TestFiles/f41 || true; \
	    ${TESTDIR}/TestFiles/f42 || true; \
	    ${TESTDIR}/TestFiles/f43 || true; \
	    ${TESTDIR}/TestFiles/f44 || true; \
	    ${TESTDIR}/TestFiles/f26 || true; \
	    ${TESTDIR}/TestFiles/f45 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libforbes

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
